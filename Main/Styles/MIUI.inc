[Variables]
GW=(450*#scale#)
GH=(170*#scale#)
P=(22*#Scale#)


Shuffle=0
Control=1
Repeat=0
Heart=1
Prog=1
;==============================================================================================
;==============================================================================================
;==============================================================================================

[MainC]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=[#PlayerType#Cover]
Format=Dec
UpdateDivider=1

[LC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light1
UpdateDivider=1

[BGC]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Dark1
UpdateDivider=1

[FGC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light1
UpdateDivider=1

[FGC2]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light2
UpdateDivider=1

; [AvC]
; Measure=Plugin
; Plugin=Chameleon
; Parent=MainC
; Color=Average
; Group=Music

[Luminance]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Luminance
OnChangeAction=[!UpdateMeterGroup DynamicColors]
UpdateDivider=1


; [BackgroundColor]
; Measure=Calc
; IfConditionMode=1
; IfCondition=Luminance > 1
; IfTrueAction=[!SetVariable BackgroundColor "[FGC1]"][!SetVariable TextColor "[BGC]"][!SetVariable AltTextColor "[BGC]"]
; IfFalseAction=[!SetVariable BackgroundColor "[BGC]"][!SetVariable TextColor "[FGC2]"][!SetVariable AltTextColor "[FGC1]"]
; ; IfCondition2=Luminance > 0.5
; ; IfTrueAction2=[!SetVariable ContrastTextColor "0,0,0"]
; ; IfFalseAction2=[!SetVariable ContrastTextColor "255,255,255"]
; OnUpdateAction=

;==============================================================================================
;==============================================================================================
;==============================================================================================

[B2]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,10,10 | StrokeWidth 0 | Fill Color 00000060
DynamicVariables=0

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,10,10 | StrokeWidth 0 | Fill Color [BGC]40
DynamicVariables=1
Group=DynamicColors

[IC]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,10,10 | StrokeWidth 0 | Fill LinearGradient MyFillGradient
MyFillGradient=195 | 0,0,0,0 ; 0.3 | 0,0,0,120 ; .9
DynamicVariables=1

[I]
Meter=Image
ImageName=[#PlayerType#Cover]
X=(#GW#-#GH#)-200
Y=-200
W=#GH#*2
H=#GH#*2
PreserveAspectRatio=2
Container=IC
DynamicVariables=1
Group=DynamicColors | Music
ImageAlpha=200

[SHead]
Meter=String
MeterStyle=S
X=#P#-8
Y=(#P#-10)
W=(#GW#-#GH#)
ClipString=2
FontWeight=500
Text=[#PlayerType#Player]
FontSize=(8*#scale#)
FontColor=[FGC2]60
DynamicVariables=1
Group=DynamicColors | Music
StringCase=UPPER
InlineSetting=CharacterSpacing | -.25 | -.25

[SName]
Meter=String
MeterStyle=S
X=#P#-8
Y=(17*#scale#)r
W=(#GW#-#GH#)+100
ClipString=1
FontWeight=500
FontSize=(17*#scale#)
FontColor=[FGC2]7F
DynamicVariables=1
MeasureName=#PlayerType#Track
Group=DynamicColors | Music
InlineSetting=CharacterSpacing | -.5 | -.5

[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(#GH#*0.17)r
W=(#GW#-#GH#)
ClipString=1
FontWeight=200
FontSize=(12*#scale#)
FontColor=[FGC1]7F
DynamicVariables=1
MeasureName=#PlayerType#Artist
Group=DynamicColors | Music
InlineSetting=CharacterSpacing | -.25 | -.25

[Heart]
Meter=Image
X=#P#-14
Y=(#GH#*0.5)
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]7F
DynamicVariables=1
Group=DynamicColors
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption Heart MeterStyle EmptyHeart][!UpdateMeter Heart][!Redraw][!CommandMeasure State#NowPlayingMedia# "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption Heart MeterStyle Fullheart][!UpdateMeter Heart][!Redraw][!CommandMeasure State#NowPlayingMedia# "ToggleThumbsUp"]


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Previous"]
ImageAlpha=150


[PlayPause]
Meter=Image
MeterStyle=
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
ImageAlpha=150

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Next"]
ImageAlpha=150

[ProgBar]
Meter=Shape
X=#P#-2
Y=(#GH#*0.74)
Shape=Line 0,0,(#GW#-#P#*1.8),0 | StrokeWidth 8 | Fill Color 0,0,0,.75 | Stroke Color [LC1]20 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#GW#-#P#*1.8)*[#PlayerType#Progress]/100),0 | StrokeWidth 8 | Fill Color 0,0,0,1 | Stroke Color [FGC2]66 | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#GW#-#P#*1.8)*[#PlayerType#Progress]/100),0,3,3 | strokeWidth 0 | Fill Color [FGC2]00 | Scale #Scale#,#Scale#
DynamicVariables=1
UpdateDivider=1
Group=DynamicColors
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#GW#-#P#*2)*100)"][!UpdateMeasure PosCalc]

[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure State#NowPlayingMedia# "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL

[CurrentTime]
Meter=String
MeterStyle=S
X=#P#-6
Y=(#GH#*0.83)
FontColor=[FGC2]
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#CurrentPosition
UpdateDivider=1
Group=DynamicColors | Music

[MediaLength]
Meter=String
MeterStyle=S
X=(#GW#-#P#*1.55)r
Y=r
FontColor=[FGC2]
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#Length
Group=DynamicColors | Music

[S]
FontFace=Google Sans
