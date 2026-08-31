.syntax unified
	.align 2, 0
	.global func_080C6878
	.thumb
	.thumb_func
	.type func_080C6878, %function
func_080C6878: @ 080C6878
	push {lr}
	ldr r0, _080C688C @ =0x02034CD8
	ldr r0, [r0, #0x00]
	bl EwramFree
	ldr r0, _080C6890 @ =0x02034CE0
	bl TaskPoolDestroy
	pop {r0}
	bx r0
_080C688C: .4byte 0x02034CD8
_080C6890: .4byte 0x02034CE0
.syntax divided
