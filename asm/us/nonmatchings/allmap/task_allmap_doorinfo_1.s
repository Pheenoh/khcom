.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_1
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_1, %function
task_allmap_doorinfo_1: @ 080D4794
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl GetKeysPressed
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D47F4
	movs r0, #0x8B
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080D47F4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x68
	bl m4aSongNumStart
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldrh r1, [r2, #0x00]
	movs r0, #0x08
	subs r0, r0, r1
	strh r0, [r2, #0x00]
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r1, r4, r2
	adds r0, r4, #0x0
	adds r0, #0xFC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r4, #0x0
	adds r0, #0xFE
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
_080D47F4:
	movs r0, #0x80
	lsls r0, r0, #0x01
	adds r5, r4, r0
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D482E
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
_080D482E:
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4844
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080D4844
	movs r0, #0x00
	b _080D4846
_080D4844:
	movs r0, #0x01
_080D4846:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
