function zipSignalThing(name, power, on, channels) {
    let zip = new JSZip();
    for (let c = 0; c != channels.length; ++c) {
        for (let p = 0; p != power.length; ++p) {
            const filename = name + " channel " + c + " power " + p + ".png";
            const image = power[p].clone().merge(channels[c]);
            const file = toPNG(image);
            zip.file(filename, file, {binary: true});
        }
        for (let o = 0; o != on.length; ++o) {
            const filename = name + " channel " + c + " on " + o + ".png";
            const image = on[o].clone().merge(channels[c]);
            const file = toPNG(image);
            zip.file(filename, file, {binary: true});
        }
    }
    return zip;
}