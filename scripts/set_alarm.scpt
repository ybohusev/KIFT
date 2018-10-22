set targetTime to the text returned of (display dialog "Enter the wake-up date/time:" default answer "" & (current date))

repeat while (current date) is less than date targetTime
  delay 2
end repeat

say "Good morning, KIFT boyz" using "Victoria"
delay 2

say "The current time is " & getTimeInHoursAndMinutes() using "Victoria"
delay 2

say "You asked us to wake you up at this time." using "Victoria"
delay 2

say "It's time to wake up, it's time to wake up!" using "Victoria"

increaseVolumeHandler_()

-- launch iTunes and play the desired song
tell application "iTunes" to play
delay 20
tell application "iTunes" to quit


on increaseVolumeHandler_()
    set theOutput to output volume of (get volume settings)
    set volume output volume (theOutput + 25)
end increaseVolumeHandler_

-- get the time in the desired format
on getTimeInHoursAndMinutes()

  -- Get the "hour"
  set timeStr to time string of (current date)
  set Pos to offset of ":" in timeStr
  set theHour to characters 1 thru (Pos - 1) of timeStr as string
  set timeStr to characters (Pos + 1) through end of timeStr as string

  -- Get the "minute"
  set Pos to offset of ":" in timeStr
  set theMin to characters 1 thru (Pos - 1) of timeStr as string
  set timeStr to characters (Pos + 1) through end of timeStr as string

  --Get "AM or PM"
  set Pos to offset of " " in timeStr
  set theSfx to characters (Pos + 1) through end of timeStr as string

  return (theHour & ":" & theMin & " " & theSfx) as string
end getTimeInHoursAndMinutes
