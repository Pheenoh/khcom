.syntax unified
	.align 2, 0
	.global task_bos_ursula_map_1
	.thumb
	.thumb_func
	.type task_bos_ursula_map_1, %function
task_bos_ursula_map_1: @ 080DC72C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	bl func_080DC578
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DC73C
	b _080DC8C4
_080DC73C:
	bl func_0802F208
	ldr r0, _080DC7A0 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r3, r0, #0x03
	ldr r0, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r1, r0, #0x03
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r3, r0
	bgt _080DC762
	ldr r0, _080DC7A4 @ =0xFFFFFB00
	cmp r3, r0
	bge _080DC764
_080DC762:
	adds r3, r0, #0x0
_080DC764:
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r1, r0
	bgt _080DC772
	ldr r0, _080DC7A4 @ =0xFFFFFB00
	cmp r1, r0
	bge _080DC774
_080DC772:
	adds r1, r0, #0x0
_080DC774:
	ldr r0, _080DC7A0 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x08]
	adds r3, r0, r3
	str r3, [r2, #0x08]
	ldr r0, [r2, #0x0C]
	adds r0, r0, r1
	str r0, [r2, #0x0C]
	str r3, [r2, #0x00]
	str r0, [r2, #0x04]
	ldr r0, _080DC7A8 @ =0xFFFF8800
	adds r1, r3, r0
	adds r0, r2, #0x0
	adds r0, #0xDA
	movs r6, #0x00
	ldsh r4, [r0, r6]
	lsls r0, r4, #0x08
	cmp r1, r0
	bge _080DC7AC
	adds r0, r4, #0x0
	adds r0, #0x78
	b _080DC7C4
_080DC7A0: .4byte 0x02039B84
_080DC7A4: .4byte 0xFFFFFB00
_080DC7A8: .4byte 0xFFFF8800
_080DC7AC:
	movs r1, #0xF0
	lsls r1, r1, #0x07
	adds r0, r3, r1
	adds r1, r2, #0x0
	adds r1, #0xDC
	movs r4, #0x00
	ldsh r3, [r1, r4]
	lsls r1, r3, #0x08
	cmp r0, r1
	ble _080DC7C8
	adds r0, r3, #0x0
	subs r0, #0x78
_080DC7C4:
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
_080DC7C8:
	bl func_080DC5B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DC7E2
	ldr r1, [r5, #0x04]
	movs r0, #0xF0
	lsls r0, r0, #0x09
	cmp r1, r0
	bne _080DC7E2
	movs r0, #0x88
	lsls r0, r0, #0x0A
	b _080DC7FA
_080DC7E2:
	bl func_080DC5B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DC800
	ldr r1, [r5, #0x04]
	movs r0, #0x88
	lsls r0, r0, #0x0A
	cmp r1, r0
	bne _080DC800
	movs r0, #0xF0
	lsls r0, r0, #0x09
_080DC7FA:
	str r0, [r5, #0x04]
	movs r0, #0x14
	strh r0, [r5, #0x08]
_080DC800:
	ldrh r0, [r5, #0x08]
	cmp r0, #0x00
	beq _080DC816
	ldr r1, [r5, #0x04]
	adds r2, r0, #0x0
	adds r0, r5, #0x0
	bl func_080058FC
	ldrh r0, [r5, #0x08]
	subs r0, #0x01
	strh r0, [r5, #0x08]
_080DC816:
	ldr r0, _080DC82C @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r2, [r3, #0x04]
	ldr r6, _080DC830 @ =0xFFFFB000
	adds r1, r2, r6
	ldr r0, _080DC834 @ =0x000087FF
	cmp r1, r0
	bgt _080DC838
	movs r0, #0xD8
	lsls r0, r0, #0x08
	b _080DC848
_080DC82C: .4byte 0x02039B84
_080DC830: .4byte 0xFFFFB000
_080DC834: .4byte 0x000087FF
_080DC838:
	movs r1, #0xA0
	lsls r1, r1, #0x07
	adds r0, r2, r1
	ldr r2, [r5, #0x00]
	cmp r0, r2
	ble _080DC84A
	ldr r4, _080DC898 @ =0xFFFFB000
	adds r0, r2, r4
_080DC848:
	str r0, [r3, #0x04]
_080DC84A:
	bl func_0802F268
	ldr r4, _080DC89C @ =0x02039B84
	ldr r1, [r4, #0x00]
	ldr r2, [r1, #0x04]
	adds r2, r2, r0
	str r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	subs r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	asrs r2, r2, #0x08
	subs r2, #0x50
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x04]
	asrs r1, r1, #0x08
	movs r6, #0x18
	negs r6, r6
	adds r0, r6, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xA0
	bhi _080DC88E
	ldr r0, _080DC8A0 @ =0x0203C57C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DC8AC
_080DC88E:
	ldr r2, _080DC8A4 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _080DC8A8 @ =0x0000DFFF
	ands r0, r1
	b _080DC8C2
_080DC898: .4byte 0xFFFFB000
_080DC89C: .4byte 0x02039B84
_080DC8A0: .4byte 0x0203C57C
_080DC8A4: .4byte 0x03007500
_080DC8A8: .4byte 0x0000DFFF
_080DC8AC:
	ldr r2, _080DC8CC @ =0x03007500
	ldrh r0, [r2, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r1, r4, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080DC8D0 @ =0x03007518
	lsls r0, r3, #0x08
	movs r1, #0xA0
	orrs r0, r1
_080DC8C2:
	strh r0, [r2, #0x00]
_080DC8C4:
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080DC8CC: .4byte 0x03007500
_080DC8D0: .4byte 0x03007518
.syntax divided
