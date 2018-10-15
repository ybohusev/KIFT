tell application "Safari"
	activate
	tell window 1
		set current tab to (make new tab with properties {URL:"https://www.google.com.ua/search?q=events+in+Kiev&oq=events+in+Kiev&aqs=chrome..69i57j0l5.2719j0j9&sourceid=chrome&ie=UTF-8"})
	end tell
end tell