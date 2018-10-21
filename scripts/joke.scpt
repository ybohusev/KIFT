tell application "Finder" to say "Ha-ha-ha"
tell application "Finder"
 activate
repeat 100 times
  make new Finder window
end repeat
end tell
tell application "Google Chrome"
 open location "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
end tell
display dialog "Ha-ha-ha-ha. Bots will conquer the world!" buttons {"FIRST BUTTON", "SECOND BUTTON"} default button 2
if the button returned of the result is "FIRST BUTTON" then
say "AAHHAHAHHAHAHAHAH"
else
tell application "Finder" to quit
end if
