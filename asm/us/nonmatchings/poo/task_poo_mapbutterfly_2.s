.syntax unified
	.align 2, 0
	.global task_poo_mapbutterfly_2
	.thumb
	.thumb_func
	.type task_poo_mapbutterfly_2, %function
task_poo_mapbutterfly_2: @ 080D26B8
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r2, [r4, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080D2704 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D2708 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r2, r2, #0x10
	asrs r6, r2, #0x10
	lsls r1, r1, #0x10
	asrs r5, r1, #0x10
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	movs r2, #0x08
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x00
	beq _080D270C
	adds r1, r4, #0x0
	adds r1, #0x34
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _080D2736
_080D2704: .4byte 0x0203C40C
_080D2708: .4byte 0x0203C3F8
_080D270C:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080D2740 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl DrawSprite
_080D2736:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D2740: .4byte 0xFFFFEFFC
.syntax divided
