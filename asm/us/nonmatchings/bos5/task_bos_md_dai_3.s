.syntax unified
	.align 2, 0
	.global task_bos_md_dai_3
	.thumb
	.thumb_func
	.type task_bos_md_dai_3, %function
task_bos_md_dai_3: @ 080FD7F0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x1C
	bl func_08012304
	ldr r0, [r4, #0x14]
	bl func_08002C10
	ldr r0, [r4, #0x18]
	bl func_080028C0
	ldr r0, _080FD81C @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _080FD820 @ =0xFFEFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	pop {r4}
	pop {r0}
	bx r0
_080FD81C: .4byte 0x02039B84
_080FD820: .4byte 0xFFEFFFFF
.syntax divided
