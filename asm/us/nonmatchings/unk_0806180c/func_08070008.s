.syntax unified
	.align 2, 0
	.global func_08070008
	.thumb
	.thumb_func
	.type func_08070008, %function
func_08070008: @ 08070008
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, _08070040 @ =0x000001AB
	adds r4, r5, r0
	ldrb r6, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_0806FE90
	ldrb r0, [r4, #0x00]
	cmp r6, r0
	beq _08070050
	ldrb r1, [r4, #0x00]
	adds r0, r6, #0x0
	bl func_08005824
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _08070030
	negs r0, r0
_08070030:
	cmp r0, #0x64
	ble _08070044
	movs r0, #0xCE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	b _0807004E
	.byte 0x00, 0x00
_08070040: .4byte 0x000001AB
_08070044:
	movs r0, #0xCE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r1, #0x00]
	asrs r0, r0, #0x01
_0807004E:
	str r0, [r1, #0x00]
_08070050:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
