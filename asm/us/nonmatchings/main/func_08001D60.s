.syntax unified
	.align 2, 0
	.global func_08001D60
	.thumb
	.thumb_func
	.type func_08001D60, %function
func_08001D60: @ 08001D60
	push {r4, lr}
	add sp, #-0x004
	ldr r0, _08001D8C @ =0x081213F8
	bl func_08000AE4
	ldr r4, _08001D90 @ =0x030074C8
	ldr r0, _08001D94 @ =0x00002BB0
	bl IwramAlloc
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _08001D98 @ =0x05000AEC
	mov r0, sp
	bl CpuSet
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08001D8C: .4byte 0x081213F8
_08001D90: .4byte 0x030074C8
_08001D94: .4byte 0x00002BB0
_08001D98: .4byte 0x05000AEC
.syntax divided
