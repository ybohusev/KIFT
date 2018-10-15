tell application "Mail"
	
	set theSubject to "Hello, KIFT"
	set theContent to "This is real KIFT from UNIT Factory!"
	set theAddress to "kift@gmail.com"
	set theSignatureName to "ybohusev, bsuprun & Co."

	set msg to make new outgoing message with properties {subject:theSubject, content:theContent, visible:true}

	tell msg to make new to recipient at end of every to recipient with properties {address:theAddress}

	set message signature of msg to signature theSignatureName

	send msg
end tell