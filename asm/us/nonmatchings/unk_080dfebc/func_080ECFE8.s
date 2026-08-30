.syntax unified
	.align 2, 0
	.global func_080ECFE8
	.thumb
	.thumb_func
	.type func_080ECFE8, %function
func_080ECFE8: @ 080ECFE8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, [r6, #0x20]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
	ldr r0, [r6, #0x70]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
	ldr r0, [r6, #0x38]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
	ldr r0, [r6, #0x3C]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
	ldr r0, [r6, #0x60]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
	movs r4, #0x00
_080ED042:
	lsls r1, r4, #0x02
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080ED060
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl func_080062F4
_080ED060:
	adds r4, #0x01
	cmp r4, #0x02
	ble _080ED042
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
