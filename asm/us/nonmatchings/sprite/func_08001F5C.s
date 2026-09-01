.syntax unified
	.align 2, 0
	.global func_08001F5C
	.thumb
	.thumb_func
	.type func_08001F5C, %function
func_08001F5C: @ 08001F5C
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08001F8C @ =0x030074C8
	ldr r3, [r2, #0x00]
	ldr r4, _08001F90 @ =0x00001AA4
	adds r2, r3, r4
	strh r0, [r2, #0x00]
	adds r0, r0, r1
	ldr r1, _08001F94 @ =0x00001AA6
	adds r3, r3, r1
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _08001F84
	movs r0, #0x10
	strh r0, [r3, #0x00]
_08001F84:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08001F8C: .4byte 0x030074C8
_08001F90: .4byte 0x00001AA4
_08001F94: .4byte 0x00001AA6
.syntax divided
