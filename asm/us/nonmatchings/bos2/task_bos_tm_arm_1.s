.syntax unified
	.align 2, 0
	.global task_bos_tm_arm_1
	.thumb
	.thumb_func
	.type task_bos_tm_arm_1, %function
task_bos_tm_arm_1: @ 080BC884
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r0, #0x8D
	lsls r0, r0, #0x02
	adds r2, r5, r0
	ldr r0, [r5, #0x0C]
	ldr r0, [r0, #0x18]
	ldr r1, [r2, #0x00]
	ldr r0, [r0, #0x2C]
	cmp r1, r0
	beq _080BC8AE
	str r0, [r2, #0x00]
	movs r1, #0xD8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r2, #0xD9
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
_080BC8AE:
	ldr r0, _080BC8C4 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080BC8C8
	adds r0, r5, #0x0
	bl _080BB924
	b _080BC8CE
	.byte 0x00, 0x00
_080BC8C4: .4byte 0x03007480
_080BC8C8:
	adds r0, r5, #0x0
	bl func_080BC304
_080BC8CE:
	ldr r0, [r5, #0x0C]
	ldr r0, [r0, #0x18]
	ldr r0, [r0, #0x2C]
	cmp r0, #0x0D
	beq _080BC924
	movs r1, #0x8F
	lsls r1, r1, #0x02
	adds r0, r5, r1
	bl AnimUpdate
	movs r2, #0xEE
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	adds r2, #0x18
	adds r1, r5, r2
	str r0, [r1, #0x00]
	ldr r0, _080BC938 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x05
	bl __umodsi3
	cmp r0, #0x00
	bne _080BC924
	ldr r0, [r5, #0x04]
	ldrh r0, [r0, #0x06]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x95
	lsls r1, r1, #0x02
	adds r4, r5, r1
	ldrb r1, [r4, #0x00]
	lsls r1, r1, #0x05
	ldr r2, _080BC93C @ =0x096FB304
	adds r1, r1, r2
	bl LoadObjPaletteBank
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	movs r1, #0x07
	ands r0, r1
	strb r0, [r4, #0x00]
_080BC924:
	movs r2, #0xDA
	lsls r2, r2, #0x01
	adds r0, r5, r2
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080BC938: .4byte 0x03007480
_080BC93C: .4byte 0x096FB304
.syntax divided
