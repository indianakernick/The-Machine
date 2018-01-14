function zipSignalThing(name, anim, channels) {
    let zip = new JSZip();
    for (let c = 0; c != channels.length; ++c) {
        for (let f = 0; f != anim.length; ++f) {
            const filename = name + " " + c + " " + f + ".png";
            const image = anim[f].clone().merge(channels[c]);
            const file = toPNG(image);
            zip.file(filename, file, {binary: true});
        }
    }
    return zip;
}
