.syntax unified
	.align 2, 0
	.global GetAngleDiff
	.thumb
	.thumb_func
	.type GetAngleDiff, %function
GetAngleDiff: @ 08005824
	adds r3, r0, #0x0
	movs r0, #0xFF
	ands r3, r0
	ands r1, r0
	subs r2, r3, r1
	movs r0, #0x80
	negs r0, r0
	cmp r2, r0
	bgt _08005840
	adds r0, r2, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	b _08005850
_08005840:
	cmp r2, #0x7F
	bgt _08005848
	lsls r0, r2, #0x10
	b _08005852
_08005848:
	ldr r2, _08005858 @ =0xFFFFFF00
	adds r0, r2, #0x0
	adds r0, r3, r0
	subs r0, r0, r1
_08005850:
	lsls r0, r0, #0x10
_08005852:
	asrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00
_08005858: .4byte 0xFFFFFF00
.syntax divided
