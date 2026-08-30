.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_obj_0
	.thumb
	.thumb_func
	.type task_wlogo_nvl_obj_0, %function
task_wlogo_nvl_obj_0: @ 080B58F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x28]
	ldr r0, [r1, #0x08]
	adds r5, r6, #0x0
	adds r5, #0x2C
	strb r0, [r5, #0x00]
	ldr r0, _080B5948 @ =0x0961C062
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r6, #0x00]
	ldr r0, _080B594C @ =0x096FADA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080B5950 @ =0x09EF35A4
	ldr r2, _080B5954 @ =0x09EF3574
	adds r0, r4, #0x0
	bl func_08005968
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B5948: .4byte 0x0961C062
_080B594C: .4byte 0x096FADA4
_080B5950: .4byte 0x09EF35A4
_080B5954: .4byte 0x09EF3574
.syntax divided
