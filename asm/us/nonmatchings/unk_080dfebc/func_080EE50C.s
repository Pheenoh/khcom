.syntax unified
	.align 2, 0
	.global func_080EE50C
	.thumb
	.thumb_func
	.type func_080EE50C, %function
func_080EE50C: @ 080EE50C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x0B
	adds r1, r4, #0x0
	bl func_080062F4
	movs r0, #0x0C
	adds r1, r4, #0x0
	bl func_080062F4
	movs r0, #0x0D
	adds r1, r4, #0x0
	bl func_080062F4
	movs r0, #0x0E
	adds r1, r4, #0x0
	bl func_080062F4
	ldr r0, [r5, #0x14]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	ldr r0, [r5, #0x34]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	ldr r0, [r5, #0x40]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r5, r5, r0
	ldr r0, [r5, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
