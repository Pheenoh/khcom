.syntax unified
	.align 2, 0
	.global task_hum_riku_2
	.thumb
	.thumb_func
	.type task_hum_riku_2, %function
task_hum_riku_2: @ 080597F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	bl func_0800EFE8
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _08059864
	movs r2, #0xDE
	lsls r2, r2, #0x01
	adds r0, r4, r2
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08059864
	movs r3, #0xE6
	lsls r3, r3, #0x01
	adds r0, r4, r3
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	lsls r0, r0, #0x01
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x00
	beq _0805983E
	cmp r1, #0x01
	beq _0805984C
	b _08059858
_0805983E:
	movs r6, #0x8C
	lsls r6, r6, #0x02
	adds r1, r4, r6
	adds r0, r4, #0x0
	bl func_08057E90
	b _08059858
_0805984C:
	movs r0, #0xA4
	lsls r0, r0, #0x02
	adds r1, r4, r0
	adds r0, r4, #0x0
	bl func_08057E90
_08059858:
	movs r2, #0xE6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08059864:
	movs r3, #0x98
	lsls r3, r3, #0x02
	adds r2, r4, r3
	movs r5, #0xA4
	lsls r5, r5, #0x02
	adds r1, r4, r5
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r6, #0x8C
	lsls r6, r6, #0x02
	adds r1, r4, r6
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r2, r4, r0
	adds r0, r2, #0x0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	movs r0, #0xE8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r1, #0x0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	adds r0, r4, #0x0
	bl func_08057E2C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
