.syntax unified
	.align 2, 0
	.global func_08001F20
	.thumb
	.thumb_func
	.type func_08001F20, %function
func_08001F20: @ 08001F20
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08001F50 @ =0x030074C8
	ldr r3, [r2, #0x00]
	ldr r4, _08001F54 @ =0x00001810
	adds r2, r3, r4
	strh r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r1, _08001F58 @ =0x00001812
	adds r3, r3, r1
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x03
	cmp r0, r1
	bls _08001F4A
	strh r1, [r3, #0x00]
_08001F4A:
	pop {r4}
	pop {r0}
	bx r0
_08001F50: .4byte 0x030074C8
_08001F54: .4byte 0x00001810
_08001F58: .4byte 0x00001812
.syntax divided
