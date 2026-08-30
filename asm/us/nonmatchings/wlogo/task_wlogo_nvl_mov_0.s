.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_mov_0
	.thumb
	.thumb_func
	.type task_wlogo_nvl_mov_0, %function
task_wlogo_nvl_mov_0: @ 080B569C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r3, #0x00
	movs r2, #0x00
	strh r2, [r6, #0x1A]
	strh r2, [r6, #0x1C]
	movs r0, #0x9C
	lsls r0, r0, #0x07
	str r0, [r6, #0x00]
	movs r0, #0xBA
	lsls r0, r0, #0x07
	str r0, [r6, #0x04]
	ldr r1, _080B5724 @ =0x096198D4
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x08]
	ldr r0, [r1, #0x08]
	str r0, [r6, #0x0C]
	ldr r0, [r1, #0x0C]
	str r0, [r6, #0x10]
	ldr r0, [r1, #0x10]
	str r0, [r6, #0x14]
	strh r2, [r6, #0x1E]
	adds r0, r6, #0x0
	adds r0, #0x20
	movs r1, #0x01
	strb r1, [r0, #0x00]
	strb r3, [r6, #0x18]
	adds r0, #0x29
	strb r1, [r0, #0x00]
	ldr r0, _080B5728 @ =0x0961C062
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r6, #0x24]
	ldr r0, _080B572C @ =0x096FADA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x28]
	adds r5, r6, #0x0
	adds r5, #0x48
	movs r0, #0x03
	strb r0, [r5, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x30
	ldr r1, _080B5730 @ =0x09EF35A4
	ldr r2, _080B5734 @ =0x09EF3574
	adds r0, r4, #0x0
	bl func_08005968
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r6, #0x2C]
	ldr r0, _080B5738 @ =0x02034C68
	movs r1, #0x0A
	bl func_08000E64
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B5724: .4byte 0x096198D4
_080B5728: .4byte 0x0961C062
_080B572C: .4byte 0x096FADA4
_080B5730: .4byte 0x09EF35A4
_080B5734: .4byte 0x09EF3574
_080B5738: .4byte 0x02034C68
.syntax divided
