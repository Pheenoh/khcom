.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_1
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_1, %function
task_bos_ursula_bubble_1: @ 080DD958
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r0, r5, #0x4
	bl func_08000EA4
	movs r4, #0x00
	adds r6, r5, #0x0
	adds r6, #0x40
	b _080DD96C
_080DD96A:
	adds r4, #0x01
_080DD96C:
	ldrh r0, [r6, #0x00]
	cmp r4, r0
	bge _080DD986
	lsls r1, r4, #0x02
	adds r0, r5, #0x0
	adds r0, #0x18
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD96A
_080DD986:
	ldrh r6, [r6, #0x00]
	cmp r4, r6
	beq _080DD990
	movs r0, #0x01
	b _080DD992
_080DD990:
	movs r0, #0x00
_080DD992:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
