# Telegram Animations

Find the official docs about Telegram stickers [here](https://core.telegram.org/stickers#animated-stickers).

No clue what `The Lottie-based .TGS format` means, but it looks compatible with Lottie.

## Telegram Web, Version K

You can use this version to get the `tgs` content of an animation.

### Option 1

1. Right-click on emoji, then click on download option.
2. Rename the file from `AnimatedSticker.tgs` to `AnimatedSticker.tgs.gz`, then unzip it using `gzip`:
   ```
   gzip -dk AnimatedSticker.tgs.gz
   ```
3. Rename the resulting file from `AnimatedSticker.tgs` to `AnimatedSticker.json`
4. Upload the file on http://rlottie.com/

### Option 2 (for hackers)

1. Start the application locally
```
pnpm start
```
2. Identify a message with the animation in a chat
3. Inspect the html around the message and identify the document-id
```
...
<div class="attachment media-sticker-wrapper" style="width: 200px; height: 200px;" data-doc-id="5134214428308275559">
  <canvas class="rlottie" width="200" height="200"></canvas>
</div>
...
```
4. Insert some code to print the `tgs` content to console
```
if(doc.id === '5134214428308275559') {
  blob.text().then((v) => {
    console.log('5134214428308275559 - TGS Content - ', v);
  });
}
```
5. Refresh the page and look in the console for the message
6. Once you got it, you can view it by using http://rlottie.com/

## Special animations

Here is a collections of some animations that we already downloaded

### Peach

This emoji was removed by Telegram due to some complaints from Apple.

The tgs can be found in [./peach.json](./peach.json)
