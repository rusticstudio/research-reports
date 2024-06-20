//go:build ignore

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <linux/ptrace.h>

char __license[] SEC("license") = "Dual MIT/GPL";

struct event {
	__u32 pid;
	__u8 comm[80];
	__u8 arg[80];
};

struct {
	__uint(type, BPF_MAP_TYPE_RINGBUF);
	__uint(max_entries, 1 << 24);
} events SEC(".maps");

// Force emitting struct event into the ELF.
const struct event *unused __attribute__((unused));

SEC("kprobe/sys_execve")
int kprobe_execve(struct pt_regs *ctx) {
	__u64 id   = bpf_get_current_pid_tgid();
	__u32 tgid = id >> 32;
	struct event *task_info;

	task_info = bpf_ringbuf_reserve(&events, sizeof(struct event), 0);
	if (!task_info) {
		return 0;
	}

	task_info->pid = tgid;
	bpf_get_current_comm(&task_info->comm, 80);
	bpf_probe_read(&task_info->arg, sizeof(task_info->arg), (char *) PT_REGS_PARM1(ctx));;
	
	bpf_ringbuf_submit(task_info, 0);

	return 0;
}
