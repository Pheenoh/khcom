.syntax unified
	.align 2, 0
	.global func_080AAD84
	.thumb
	.thumb_func
	.type func_080AAD84, %function
func_080AAD84: @ 080AAD84
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r1, _080AADB8 @ =0x0000063C
	adds r0, r0, r1
	bl func_08000C8C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _080AADCA
	lsls r0, r4, #0x10
	asrs r6, r0, #0x10
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
_080AADA4:
	movs r1, #0x22
	ldsh r0, [r3, r1]
	cmp r0, r6
	bne _080AADBC
	movs r1, #0x24
	ldsh r0, [r3, r1]
	cmp r0, r4
	bne _080AADBC
	movs r0, #0x01
	b _080AADCC
_080AADB8: .4byte 0x0000063C
_080AADBC:
	adds r0, r3, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _080AADA4
_080AADCA:
	movs r0, #0x00
_080AADCC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
