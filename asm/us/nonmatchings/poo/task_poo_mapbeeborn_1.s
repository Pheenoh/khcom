.syntax unified
	.align 2, 0
	.global task_poo_mapbeeborn_1
	.thumb
	.thumb_func
	.type task_poo_mapbeeborn_1, %function
task_poo_mapbeeborn_1: @ 080D2518
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r0, #0x98
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D2570
	adds r0, r4, #0x0
	adds r0, #0x4E
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D2568
	adds r5, r4, #0x0
	adds r5, #0x94
	ldr r0, [r5, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	bne _080D2570
	adds r1, r4, #0x0
	adds r1, #0x99
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D2570
	strb r2, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x80
	ldr r1, _080D2564 @ =0x09EF4D20
	adds r2, r4, #0x0
	adds r2, #0x10
	bl func_08000E14
	str r0, [r5, #0x00]
	b _080D2570
	.byte 0x00, 0x00
_080D2564: .4byte 0x09EF4D20
_080D2568:
	adds r1, r4, #0x0
	adds r1, #0x99
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080D2570:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
