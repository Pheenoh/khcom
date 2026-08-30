.syntax unified
	.align 2, 0
	.global task_allmap_pusha_0
	.thumb
	.thumb_func
	.type task_allmap_pusha_0, %function
task_allmap_pusha_0: @ 080D4BB8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _080D4C10 @ =0x0203C460
	str r4, [r0, #0x00]
	str r1, [r4, #0x0C]
	ldrh r2, [r1, #0x30]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	ldr r2, _080D4C14 @ =0x0203C540
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	movs r5, #0x00
	strh r0, [r4, #0x2C]
	ldrh r1, [r1, #0x32]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4C18 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	strh r0, [r4, #0x2E]
	ldr r0, _080D4C1C @ =0x0976DCB0
	movs r1, #0x80
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D4C20 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, _080D4C24 @ =0x0976DC9C
	str r0, [r4, #0x08]
	strh r5, [r4, #0x10]
	adds r0, r4, #0x0
	adds r0, #0x14
	movs r1, #0x01
	bl func_08000E64
	str r5, [r4, #0x28]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D4C10: .4byte 0x0203C460
_080D4C14: .4byte 0x0203C540
_080D4C18: .4byte 0x0203C53C
_080D4C1C: .4byte 0x0976DCB0
_080D4C20: .4byte 0x0984A1D8
_080D4C24: .4byte 0x0976DC9C
.syntax divided
