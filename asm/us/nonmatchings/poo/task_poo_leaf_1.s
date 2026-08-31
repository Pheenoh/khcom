.syntax unified
	.align 2, 0
	.global task_poo_leaf_1
	.thumb
	.thumb_func
	.type task_poo_leaf_1, %function
task_poo_leaf_1: @ 080CF2FC
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CF36A
	adds r0, r4, #0x0
	adds r0, #0x62
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080CF36A
	adds r1, r4, #0x0
	adds r1, #0x90
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080CF36A
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005B64
	movs r0, #0xE0
	bl m4aSongNumStart
	adds r5, r4, #0x0
	adds r5, #0x94
	ldrh r0, [r5, #0x00]
	bl func_080D2C1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CF36A
	ldr r2, [r4, #0x24]
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r2, r2, r0
	ldr r3, [r4, #0x28]
	movs r0, #0x80
	lsls r0, r0, #0x06
	adds r3, r3, r0
	ldr r0, [r4, #0x2C]
	str r0, [sp, #0x000]
	movs r0, #0x02
	movs r1, #0x03
	bl func_080C7BF8
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080CF36A
	ldrh r0, [r5, #0x00]
	bl func_080D2BF8
_080CF36A:
	movs r0, #0x01
	add sp, #0x004
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
