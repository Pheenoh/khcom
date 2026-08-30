.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_0
	.thumb
	.thumb_func
	.type task_bos_pc_flt_0, %function
task_bos_pc_flt_0: @ 0810BD1C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _0810BDBC @ =0x09CB8F54
	movs r1, #0xDC
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x34]
	ldr r0, _0810BDC0 @ =0x09D693D4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r4, #0x38]
	adds r5, r4, #0x0
	adds r5, #0x9C
	ldr r1, _0810BDC4 @ =0x09EFBBEC
	ldr r2, _0810BDC8 @ =0x09EFBBBC
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	adds r0, #0x40
	movs r1, #0x07
	movs r2, #0x1A
	movs r3, #0x04
	bl func_080122AC
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x00]
	strh r0, [r4, #0x02]
	ldrb r0, [r6, #0x00]
	strb r0, [r4, #0x04]
	strb r1, [r4, #0x05]
	strb r1, [r4, #0x06]
	strb r1, [r4, #0x07]
	ldrb r0, [r6, #0x00]
	lsls r0, r0, #0x0E
	ldrh r1, [r6, #0x02]
	adds r0, r0, r1
	strh r0, [r4, #0x08]
	movs r0, #0xF4
	lsls r0, r0, #0x08
	str r0, [r4, #0x0C]
	movs r0, #0xAA
	lsls r0, r0, #0x09
	str r0, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x07
	strh r0, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x06
	strh r0, [r4, #0x16]
	movs r0, #0xB4
	lsls r0, r0, #0x02
	strh r0, [r4, #0x18]
	ldr r0, [r6, #0x04]
	str r0, [r4, #0x1C]
	ldr r0, [r6, #0x08]
	str r0, [r4, #0x20]
	ldr r0, [r6, #0x0C]
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x10]
	str r0, [r4, #0x3C]
	adds r0, r4, #0x0
	bl _0810BAE4
	adds r0, r4, #0x0
	bl func_0810BCD4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810BDBC: .4byte 0x09CB8F54
_0810BDC0: .4byte 0x09D693D4
_0810BDC4: .4byte 0x09EFBBEC
_0810BDC8: .4byte 0x09EFBBBC
.syntax divided
