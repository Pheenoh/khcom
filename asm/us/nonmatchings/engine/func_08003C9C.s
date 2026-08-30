.syntax unified
	.align 2, 0
	.global func_08003C9C
	.thumb
	.thumb_func
	.type func_08003C9C, %function
func_08003C9C: @ 08003C9C
	push {r4, r5, lr}
	adds r1, r0, #0x0
	cmp r1, #0x00
	ble _08003CCA
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	ble _08003CAE
	adds r0, r1, #0x0
_08003CAE:
	lsls r5, r1, #0x08
_08003CB0:
	adds r4, r0, #0x0
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl __divsi3
	adds r0, r0, r4
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	cmp r0, r4
	blt _08003CB0
	adds r0, r4, #0x0
	b _08003CCC
_08003CCA:
	movs r0, #0x00
_08003CCC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
