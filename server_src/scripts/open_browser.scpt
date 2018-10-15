tell application "Safari"
	activate
	tell window 0
		set current tab to (make new tab with properties {URL:"https://unit.ua/en/"})
	end tell
end tell
