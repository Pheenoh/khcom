.syntax unified
	.align 2, 0
	.global task_poo_pile_0
	.thumb
	.thumb_func
	.type task_poo_pile_0, %function
task_poo_pile_0: @ 080CD214
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, [r4, #0x00]
	str r0, [r5, #0x24]
	ldr r0, [r4, #0x04]
	str r0, [r5, #0x28]
	movs r0, #0x00
	str r0, [r5, #0x2C]
	str r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x0C
	ldr r1, _080CD248 @ =0x09EF5C8C
	ldr r2, _080CD24C @ =0x09EF5C6C
	bl func_08005968
	ldr r1, [r4, #0x10]
	cmp r1, #0x08
	bne _080CD250
	bl func_080CD198
	adds r1, r5, #0x0
	adds r1, #0xB0
	strh r0, [r1, #0x00]
	adds r0, r1, #0x0
	b _080CD256
_080CD248: .4byte 0x09EF5C8C
_080CD24C: .4byte 0x09EF5C6C
_080CD250:
	adds r0, r5, #0x0
	adds r0, #0xB0
	strh r1, [r0, #0x00]
_080CD256:
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x34
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x2C]
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0xCC
	movs r4, #0x00
	strb r4, [r0, #0x00]
	subs r0, #0x18
	movs r1, #0x01
	bl func_08000E64
	adds r0, r5, #0x0
	adds r0, #0xC8
	str r4, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
