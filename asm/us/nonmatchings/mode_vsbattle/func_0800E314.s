.syntax unified
	.align 2, 0
	.global func_0800E314
	.thumb
	.thumb_func
	.type func_0800E314, %function
func_0800E314: @ 0800E314
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r6, r2, #0x0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	bne _0800E326
	str r4, [r5, #0x0C]
	b _0800E328
_0800E326:
	str r4, [r5, #0x10]
_0800E328:
	ldrh r0, [r6, #0x04]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080028F8
	str r0, [r4, #0x04]
	ldr r0, [r6, #0x00]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	str r0, [r4, #0x0C]
	ldr r0, [r5, #0x44]
	str r0, [r4, #0x28]
	ldr r0, [r5, #0x48]
	str r0, [r4, #0x2C]
	ldr r0, [r5, #0x4C]
	str r0, [r4, #0x30]
	movs r0, #0x00
	strh r0, [r4, #0x34]
	adds r0, r4, #0x0
	adds r0, #0x10
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
