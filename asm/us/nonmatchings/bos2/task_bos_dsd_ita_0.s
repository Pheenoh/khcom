.syntax unified
	.align 2, 0
	.global task_bos_dsd_ita_0
	.thumb
	.thumb_func
	.type task_bos_dsd_ita_0, %function
task_bos_dsd_ita_0: @ 080C3F24
	push {r4, r5, lr}
	adds r5, r0, #0x0
	str r1, [r5, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x74
	movs r3, #0x00
	movs r2, #0x00
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x76
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strb r3, [r0, #0x00]
	movs r0, #0x96
	lsls r0, r0, #0x09
	str r0, [r5, #0x60]
	movs r0, #0xBE
	lsls r0, r0, #0x09
	str r0, [r5, #0x64]
	ldr r0, _080C3FA0 @ =0xFFFF8800
	str r0, [r5, #0x68]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r5, #0x6C]
	movs r0, #0x19
	str r0, [r5, #0x70]
	adds r0, r5, #0x0
	adds r0, #0x7C
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x02
	str r2, [r0, #0x00]
	adds r4, r5, #0x4
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x20
	movs r3, #0x03
	bl func_080122AC
	ldr r1, [r5, #0x60]
	ldr r2, [r5, #0x64]
	ldr r3, [r5, #0x68]
	adds r0, r4, #0x0
	bl func_08012324
	adds r1, r5, #0x0
	adds r1, #0x88
	ldr r0, _080C3FA4 @ =0x09EF3BF8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _080C3FA8 @ =0x09EF3C18
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C3FA0: .4byte 0xFFFF8800
_080C3FA4: .4byte 0x09EF3BF8
_080C3FA8: .4byte 0x09EF3C18
.syntax divided
