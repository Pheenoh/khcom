.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_0
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_0, %function
task_bos_ursula_bubble_0: @ 080DD8FC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r0, r4, #0x4
	movs r1, #0x0A
	bl func_08000E64
	adds r5, r4, #0x0
	adds r5, #0x40
	movs r0, #0x00
	strh r0, [r5, #0x00]
	bl func_080DC5E8
	cmp r0, #0x01
	beq _080DD92A
	cmp r0, #0x01
	bcc _080DD938
	cmp r0, #0x02
	bne _080DD938
	adds r0, r4, #0x0
	bl func_080DD8A8
	strh r0, [r5, #0x00]
	b _080DD948
_080DD92A:
	adds r0, r4, #0x0
	bl func_080DD854
	ldrh r1, [r5, #0x00]
	adds r0, r0, r1
	strh r0, [r5, #0x00]
	b _080DD948
_080DD938:
	adds r0, r4, #0x0
	bl func_080DD7C4
	adds r1, r4, #0x0
	adds r1, #0x40
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
_080DD948:
	movs r0, #0xA0
	lsls r0, r0, #0x02
	bl func_0811FE70
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
