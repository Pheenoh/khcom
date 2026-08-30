.syntax unified
	.align 2, 0
	.global func_0800F4C8
	.thumb
	.thumb_func
	.type func_0800F4C8, %function
func_0800F4C8: @ 0800F4C8
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, _0800F4F8 @ =0x02039B84
	ldr r3, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xDA
	movs r2, #0x00
	ldsh r1, [r1, r2]
	adds r1, r1, r4
	lsls r1, r1, #0x08
	ldr r2, [r0, #0x44]
	cmp r2, r1
	blt _0800F4FC
	adds r0, r3, #0x0
	adds r0, #0xDC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, r0, r4
	lsls r0, r0, #0x08
	cmp r2, r0
	bgt _0800F4FC
	movs r0, #0x00
	b _0800F4FE
_0800F4F8: .4byte 0x02039B84
_0800F4FC:
	movs r0, #0x01
_0800F4FE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
