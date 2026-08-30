.syntax unified
	.align 2, 0
	.global task_bos_dsd_circle_0
	.thumb
	.thumb_func
	.type task_bos_dsd_circle_0, %function
task_bos_dsd_circle_0: @ 080C46C0
	str r1, [r0, #0x00]
	ldr r1, _080C46FC @ =0x0961A89E
	movs r2, #0x00
	ldsh r1, [r1, r2]
	lsls r1, r1, #0x08
	movs r2, #0xDC
	lsls r2, r2, #0x08
	adds r1, r1, r2
	str r1, [r0, #0x08]
	ldr r1, _080C4700 @ =0x0961A8B0
	movs r2, #0x00
	ldsh r1, [r1, r2]
	lsls r1, r1, #0x08
	movs r2, #0xB4
	lsls r2, r2, #0x09
	adds r1, r1, r2
	str r1, [r0, #0x0C]
	movs r1, #0x00
	str r1, [r0, #0x10]
	movs r2, #0x00
	strh r1, [r0, #0x14]
	strh r1, [r0, #0x16]
	strb r2, [r0, #0x1A]
	strh r1, [r0, #0x1C]
	strh r1, [r0, #0x18]
	ldr r1, _080C4704 @ =0x09EF3C50
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x04]
	bx lr
	.byte 0x00, 0x00
_080C46FC: .4byte 0x0961A89E
_080C4700: .4byte 0x0961A8B0
_080C4704: .4byte 0x09EF3C50
.syntax divided
