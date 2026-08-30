.syntax unified
	.align 2, 0
	.global task_poo_mapbutterflyborn_2
	.thumb
	.thumb_func
	.type task_poo_mapbutterflyborn_2, %function
task_poo_mapbutterflyborn_2: @ 080D2818
	push {r4, r5, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080D286C @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	ldr r2, _080D2870 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0x00
	str r5, [sp, #0x000]
	movs r2, #0x20
	str r2, [sp, #0x004]
	movs r2, #0x00
	movs r3, #0x18
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D2874
	adds r1, r4, #0x0
	adds r1, #0x98
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D28A4
	strb r5, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0x99
	strb r5, [r0, #0x00]
	b _080D28A4
_080D286C: .4byte 0x0203C40C
_080D2870: .4byte 0x0203C3F8
_080D2874:
	adds r5, r4, #0x0
	adds r5, #0x98
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080D2896
	adds r0, r4, #0x0
	adds r0, #0x20
	movs r1, #0x06
	movs r2, #0x28
	movs r3, #0x00
	bl func_080122AC
	movs r0, #0x01
	strb r0, [r5, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x99
	strb r0, [r1, #0x00]
_080D2896:
	adds r4, #0x80
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
_080D28A4:
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
