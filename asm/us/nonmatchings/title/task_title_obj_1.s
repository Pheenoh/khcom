.syntax unified
	.align 2, 0
	.global task_title_obj_1
	.thumb
	.thumb_func
	.type task_title_obj_1, %function
task_title_obj_1: @ 080D669C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl func_080D6294
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D66EE
	adds r1, r5, #0x0
	adds r1, #0x62
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D66BA
	subs r0, #0x01
	strh r0, [r1, #0x00]
	b _080D66EE
_080D66BA:
	adds r4, r5, #0x0
	adds r4, #0x60
	ldrh r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D66EE
	adds r0, r5, #0x0
	adds r0, #0x28
	ldr r1, [r5, #0x2C]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x44]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D66EE
	ldr r1, _080D66F8 @ =0x02034ED0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080D66EE:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D66F8: .4byte 0x02034ED0
.syntax divided
