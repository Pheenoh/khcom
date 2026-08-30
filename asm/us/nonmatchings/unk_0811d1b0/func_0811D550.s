.syntax unified
	.align 2, 0
	.global func_0811D550
	.thumb
	.thumb_func
	.type func_0811D550, %function
func_0811D550: @ 0811D550
	ldr r3, _0811D578 @ =0x0203C7F0
	lsls r0, r0, #0x02
	adds r2, r3, #0x0
	adds r2, #0x08
	adds r2, r0, r2
	adds r1, r3, #0x0
	adds r1, #0x18
	adds r1, r0, r1
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	adds r2, r3, #0x0
	adds r2, #0x10
	adds r2, r0, r2
	adds r1, r3, #0x0
	adds r1, #0x20
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_0811D578: .4byte 0x0203C7F0
.syntax divided
