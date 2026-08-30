.syntax unified
	.align 2, 0
	.global func_080AAC40
	.thumb
	.thumb_func
	.type func_080AAC40, %function
func_080AAC40: @ 080AAC40
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_08085FA4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_08085770
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080AAC64 @ =0x02039BB0
	adds r1, #0xFA
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	bgt _080AAC68
	movs r0, #0x01
	b _080AAC80
_080AAC64: .4byte 0x02039BB0
_080AAC68:
	movs r3, #0xC5
	lsls r3, r3, #0x03
	adds r0, r4, r3
	ldr r1, _080AAC88 @ =0x09EE7FA8
	adds r3, #0xE5
	adds r2, r4, r3
	bl func_08000E14
	movs r0, #0x69
	bl func_0811FE70
	movs r0, #0x00
_080AAC80:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080AAC88: .4byte 0x09EE7FA8
.syntax divided
