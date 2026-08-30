.syntax unified
	.align 2, 0
	.global func_080DDD30
	.thumb
	.thumb_func
	.type func_080DDD30, %function
func_080DDD30: @ 080DDD30
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	bne _080DDD6C
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r0, r4, r2
	strh r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	adds r0, #0x24
	movs r1, #0x01
	bl func_0801C2DC
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x02
	str r0, [r1, #0x00]
_080DDD6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
