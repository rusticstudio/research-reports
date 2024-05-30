# Telegram Animations

Find the official docs about Telegram animations [here](https://core.telegram.org/stickers#animated-stickers).

No clue what `The Lottie-based .TGS format` means, but it looks compatible with [Lottie](https://github.com/airbnb/lottie).

## Emojies vs Stickers

In Telegram there is a distinction between emojies and stickers.

Animated emojies are Telegram native emojies, they are interactive, which means that clicking on them will trigger an animation and some additional effect.

Stickers are custom animations added to Telegram, anyone can add their custom stickers. Clicking on them will display the full sticker set.

## Download tgs files from Telegram

You can follow the steps below to get the `tgs` content of an animation.

### Option 1 (Download using Telegram Web)

This option will work only for stickers, it won't work for animated emojies.

If you need to download an animated emoji, then note that there is a sticker set that contains all native Telegram animated emojies, check [Animated Emoji](https://t.me/addstickers/AnimatedEmojies) sticker set, so you can find in this set your emoji and follow the steps below.

1. Open Telegram Web (works with both Version A and Version K)
2. Right-click on a sticker, then click on `Download`
3. Rename the file from `AnimatedSticker.tgs` to `AnimatedSticker.tgs.gz`, then unzip it using `gzip`:
   ```
   gzip -dk AnimatedSticker.tgs.gz
   ```
4. Rename the resulting file from `AnimatedSticker.tgs` to `AnimatedSticker.json`
5. Now you can view it on http://rlottie.com/

### Option 2 (for hackers)

1. Clone [Telegram Web Version K](https://github.com/morethanwords/tweb) locally
2. Start the application locally
   ```
   pnpm start
   ```
3. Identify a message with the animation in a chat
4. Inspect the html around the message that contains the sticker/emoji and identify the `data-doc-id`
   ```
   ...
   <div class="attachment media-sticker-wrapper" style="width: 200px; height: 200px;" data-doc-id="5134214428308275559">
     <canvas class="rlottie" width="200" height="200"></canvas>
   </div>
   ...
   ```
4. Insert some code to print the `tgs` content to console (use your `data-doc-id`)
   ```
   if(doc.id === '5134214428308275559') {
     blob.text().then((v) => {
       console.log('5134214428308275559 - TGS Content - ', v);
     });
   }
   ```
5. Refresh the page and look in the console for the message that contains you `data-doc-id`
6. Save the json to a file
7. Once you got it, you can view it by using http://rlottie.com/

## Special animations

Here is a collections of some special animations that we think are worth to keep.

### Deleted Telegram Peach (🍑) Emoji

This emoji was removed by Telegram due to some complaints from Apple.
Users tried to get it back, but were denied, check the ticket [here](https://bugs.telegram.org/c/11912).

Download the `tgs` from [peach.json](./peach.json) file
