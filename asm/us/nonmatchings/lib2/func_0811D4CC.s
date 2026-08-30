.syntax unified
	.align 2, 0
	.global func_0811D4CC
	.thumb
	.thumb_func
	.type func_0811D4CC, %function
func_0811D4CC: @ 0811D4CC
	push {r4, r5, r6, lr}
	bl func_0811D518
	movs r4, #0x00
	ldr r1, _0811D4F8 @ =0x0203C7F0
	ldr r0, [r1, #0x40]
	cmp r4, r0
	bcs _0811D4F0
	adds r5, r1, #0x0
	adds r6, r5, #0x0
_0811D4E0:
	ldm r6!, {r0}
	ldr r1, [r5, #0x54]
	bl _0811D5B4
	adds r4, #0x01
	ldr r0, [r5, #0x40]
	cmp r4, r0
	bcc _0811D4E0
_0811D4F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0811D4F8: .4byte 0x0203C7F0
.syntax divided
