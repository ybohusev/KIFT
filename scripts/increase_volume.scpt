on increaseVolumeHandler_()
    set theOutput to output volume of (get volume settings)
    set volume output volume (theOutput + 25)
end increaseVolumeHandler_

increaseVolumeHandler_()
