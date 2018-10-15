-- set volume output volume 100
on increaseVolumeHandler_()
    set theOutput to output volume of (get volume settings)
    set volume output volume (theOutput + 25)
    -- do shell script "afplay /System/Library/Sounds/Pop.aiff"
end increaseVolumeHandler_

increaseVolumeHandler_()
