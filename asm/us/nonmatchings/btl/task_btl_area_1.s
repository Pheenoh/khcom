.syntax unified
	.align 2, 0
	.global task_btl_area_1
	.thumb
	.thumb_func
	.type task_btl_area_1, %function
task_btl_area_1: @ 0801D644
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x09]
	cmp r0, #0x00
	bne _0801D650
	strb r0, [r2, #0x08]
	b _0801D686
_0801D650:
	ldr r0, _0801D674 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0xB4
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _0801D666
	movs r1, #0x00
	movs r0, #0x14
	strh r0, [r2, #0x0A]
	strb r1, [r3, #0x00]
_0801D666:
	movs r1, #0x0A
	ldsh r0, [r2, r1]
	ldrh r1, [r2, #0x0A]
	cmp r0, #0x00
	ble _0801D678
	movs r0, #0x01
	b _0801D67A
_0801D674: .4byte 0x02039B84
_0801D678:
	movs r0, #0x00
_0801D67A:
	strb r0, [r2, #0x08]
	lsls r0, r1, #0x10
	cmp r0, #0x00
	ble _0801D686
	subs r0, r1, #0x1
	strh r0, [r2, #0x0A]
_0801D686:
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
.syntax divided
