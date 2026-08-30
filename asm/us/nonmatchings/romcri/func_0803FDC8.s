.syntax unified
	.align 2, 0
	.global func_0803FDC8
	.thumb
	.thumb_func
	.type func_0803FDC8, %function
func_0803FDC8: @ 0803FDC8
	push {r4, lr}
	movs r3, #0x00
	movs r2, #0x00
	ldsh r1, [r0, r2]
	cmp r3, r1
	bge _0803FDEE
	ldr r4, _0803FDF8 @ =0x09EDA4EC
	ldr r2, [r0, #0x04]
_0803FDD8:
	ldr r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r2, #0x0C
	subs r1, #0x01
	cmp r1, #0x00
	bne _0803FDD8
_0803FDEE:
	adds r0, r3, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0803FDF8: .4byte 0x09EDA4EC
.syntax divided
