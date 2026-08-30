.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_0
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_0, %function
task_allmap_doorinfo_0: @ 080D469C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	movs r4, #0x00
_080D46A4:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x1F
	ble _080D46A4
	movs r0, #0x28
	bl func_08000918
	adds r1, r6, #0x0
	adds r1, #0xF4
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r6, #0x00]
	bl func_080D5494
	strb r0, [r6, #0x04]
	ldrh r1, [r6, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D473C @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r5, r6, #0x0
	adds r5, #0xFC
	strh r0, [r5, #0x00]
	ldrh r1, [r6, #0x02]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4740 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r4, r6, #0x0
	adds r4, #0xFE
	strh r0, [r4, #0x00]
	movs r0, #0x86
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xD0
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4728
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4728
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4744
_080D4728:
	movs r3, #0x88
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0x84
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	bl func_080D44D4
	b _080D4756
_080D473C: .4byte 0x0203C540
_080D4740: .4byte 0x0203C53C
_080D4744:
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x84
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	bl func_080D42D4
_080D4756:
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r2, #0x00
	movs r0, #0x08
	strh r0, [r1, #0x00]
	adds r0, #0xFC
	adds r1, r6, r0
	movs r3, #0x00
	ldsh r0, [r5, r3]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x84
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x0E
	movs r2, #0x08
	bl func_08006238
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
