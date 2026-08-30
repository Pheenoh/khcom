.syntax unified
	.align 2, 0
	.global task_bos_md_hahen_1
	.thumb
	.thumb_func
	.type task_bos_md_hahen_1, %function
task_bos_md_hahen_1: @ 080FD8D4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r5, #0x01
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x0C]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	ldr r2, [r4, #0x10]
	adds r0, r0, r2
	str r0, [r4, #0x04]
	ldr r1, _080FD92C @ =0x000117FF
	cmp r0, r1
	bgt _080FD8F4
	negs r0, r2
	str r0, [r4, #0x10]
_080FD8F4:
	ldr r0, [r4, #0x08]
	ldr r1, [r4, #0x14]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	adds r1, #0x66
	str r1, [r4, #0x14]
	cmp r0, #0x00
	ble _080FD922
	movs r0, #0x00
	str r0, [r4, #0x08]
	lsls r0, r1, #0x03
	movs r1, #0x0A
	bl func_0811D5EC
	negs r0, r0
	str r0, [r4, #0x14]
	ldrh r0, [r4, #0x24]
	subs r0, #0x01
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _080FD922
	movs r5, #0x00
_080FD922:
	adds r0, r5, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080FD92C: .4byte 0x000117FF
.syntax divided
