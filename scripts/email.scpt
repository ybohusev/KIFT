tell application "Mail"
	
	set theSubject to "Hello, KIFT"
	set theContent to "This is real KIFT from UNIT Factory!"
	set theAddress to "kift@gmail.com"

	set msg to make new outgoing message with properties {subject:theSubject, content:theContent, visible:true}

	tell msg to make new to recipient at end of every to recipient with properties {address:theAddress}

	send msg
end tell
