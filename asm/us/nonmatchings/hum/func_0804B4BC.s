.syntax unified
	.align 2, 0
	.global func_0804B4BC
	.thumb
	.thumb_func
	.type func_0804B4BC, %function
func_0804B4BC: @ 0804B4BC
	push {r4, lr}
	adds r3, r0, #0x0
	movs r4, #0xAE
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r3, r1
	str r2, [r0, #0x00]
	adds r4, #0x14
	adds r1, r3, r4
	movs r0, #0x16
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r3, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r4, #0x18
	adds r1, r3, r4
	ldr r0, _0804B4F0 @ =0xFFFFF980
	str r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0804B4F0: .4byte 0xFFFFF980
.syntax divided
