.syntax unified
	.align 2, 0
	.global func_080EE580
	.thumb
	.thumb_func
	.type func_080EE580, %function
func_080EE580: @ 080EE580
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, [r5, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_080062F4
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
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
