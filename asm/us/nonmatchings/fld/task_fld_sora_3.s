.syntax unified
	.align 2, 0
	.global task_fld_sora_3
	.thumb
	.thumb_func
	.type task_fld_sora_3, %function
task_fld_sora_3: @ 080342DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r0, _08034348 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r5, r0, #0x0
	adds r5, #0x18
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
	ldr r2, _0803434C @ =0x02039BB0
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08034350
	ldr r0, [r5, #0x10]
	str r0, [r2, #0x28]
	adds r1, r2, #0x0
	adds r1, #0x14
	adds r0, r5, #0x0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldrb r1, [r5, #0x14]
	adds r0, r2, #0x0
	adds r0, #0x24
	strb r1, [r0, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	strh r0, [r2, #0x30]
	adds r0, r4, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x2C]
	adds r0, r4, #0x0
	adds r0, #0xB0
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x34]
	adds r0, r4, #0x0
	adds r0, #0xB4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x38]
	adds r0, r4, #0x0
	adds r0, #0xB8
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x3C]
	b _08034358
_08034348: .4byte 0x02039BA0
_0803434C: .4byte 0x02039BB0
_08034350:
	ldrb r1, [r5, #0x14]
	adds r0, r2, #0x0
	adds r0, #0x24
	strb r1, [r0, #0x00]
_08034358:
	adds r0, r4, #0x0
	adds r0, #0x24
	bl func_08000F0C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
