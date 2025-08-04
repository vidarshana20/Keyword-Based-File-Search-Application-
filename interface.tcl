#!/usr/bin/env wish

wm title . "Mini Search Engine"
wm resizable . 0 0
wm geometry . "+400+200"
set myFont "Helvetica 11"

# ---------- FUNCTIONS ----------
proc highlightText {textWidget keyword} {
    $textWidget tag remove highlight 1.0 end
    if {$keyword eq ""} { return }
    set start 1.0
    while {[set pos [$textWidget search -nocase $keyword $start end]] ne ""} {
        set endPos "$pos + [string length $keyword]c"
        $textWidget tag add highlight $pos $endPos
        set start $endPos
    }
    $textWidget tag configure highlight -background yellow -foreground black
}

proc searchQuery {} {
    set query [.entry get]
    if {$query eq ""} {
        .text delete 1.0 end
        .text insert end "Please enter a search term.\n"
        return
    }
    set result [exec ./search_engine.exe $query]
    .text delete 1.0 end
    .text insert end $result
    highlightText .text $query
}

proc clearResults {} {
    .entry delete 0 end
    .text delete 1.0 end
    .text insert end "Output cleared.\n"
}

# ---------- WIDGETS ----------
label .l -text "Enter search term:" -font $myFont
entry .entry -width 30 -font $myFont

button .b -text "Search" -command searchQuery -font $myFont -background "#0066cc" -foreground white
button .clear -text "Clear" -command clearResults -font $myFont -background "#999999" -foreground white

text .text -width 70 -height 15 -wrap word -font $myFont -bg #f9f9f9

# ---------- LAYOUT ----------
pack .l -padx 10 -pady 5
pack .entry -padx 10
pack .b .clear -side left -padx 10 -pady 5
pack .text -padx 10 -pady 10
